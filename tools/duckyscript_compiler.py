#!/usr/bin/env python3
"""
DuckyScript to C++ Compiler for ATTiny85 Ducky
Converts USB Rubber Ducky script files to Arduino C++ code
"""

import sys
import os
import random
import string


class DuckyScriptCompiler:
    def __init__(self):
        self.language = "lang_us"
        self.defines = {}
        self.output_lines = []

    def _generate_random_string(self, length, charset):
        """Generate random string from given charset"""
        return "".join(random.choice(charset) for _ in range(length))

    def _process_rand_command(self, line):
        """Process RAND_* commands and return the random string"""
        parts = line.split()
        command = parts[0]
        length = int(parts[1]) if len(parts) > 1 else None

        # Determine charset and default length (order matters - check _UPPER variants first!)
        if command == "RAND_HEX":
            charset = string.hexdigits[:16]  # 0-9a-f
            default_length = 2
        elif command == "RAND_NUM":
            charset = string.digits
            default_length = 1
        elif command == "RAND_ALPHA_UPPER":
            charset = string.ascii_uppercase
            default_length = 1
        elif command == "RAND_ALPHA":
            charset = string.ascii_lowercase
            default_length = 1
        elif command == "RAND_ALPHANUM_UPPER":
            charset = string.ascii_uppercase + string.digits
            default_length = 2
        elif command == "RAND_ALPHANUM":
            charset = string.ascii_lowercase + string.digits
            default_length = 2
        else:
            return None

        # Use provided length or default
        actual_length = length if length is not None else default_length
        return self._generate_random_string(actual_length, charset)

    def parse_line(self, line):
        """Parse a single line of DuckyScript"""
        line = line.strip()

        # Skip empty lines and comments
        if not line or line.startswith("REM "):
            return

        # Handle DEFINE
        if line.startswith("DEFINE "):
            parts = line.split(None, 2)
            if len(parts) == 3:
                self.defines[parts[1]] = parts[2]
            return

        # Handle DUCKY_LANG
        if line.startswith("DUCKY_LANG "):
            lang = line.split()[1].upper()
            self.language = f"lang_{lang.lower()}"
            return

        # Replace defines in line (before RAND processing)
        for define_key, define_value in self.defines.items():
            line = line.replace(define_key, define_value)

        # Process RAND_* commands in line
        while "RAND_" in line:
            # Find RAND_ command
            rand_start = line.find("RAND_")
            if rand_start == -1:
                break

            # Find end of RAND command (space or end of line)
            rand_end = rand_start
            while rand_end < len(line) and line[rand_end] not in (" ", "\t", "\n"):
                rand_end += 1

            # Check if there's a number after the command
            remaining = line[rand_end:].lstrip()
            if remaining and remaining[0].isdigit():
                # Extract the number
                num_end = 0
                while num_end < len(remaining) and remaining[num_end].isdigit():
                    num_end += 1
                rand_command = line[rand_start:rand_end] + " " + remaining[:num_end]
                replace_end = rand_end + len(line[rand_end:]) - len(remaining) + num_end
            else:
                rand_command = line[rand_start:rand_end]
                replace_end = rand_end

            # Generate random string
            random_str = self._process_rand_command(rand_command)
            if random_str:
                line = line[:rand_start] + random_str + line[replace_end:]
            else:
                break  # Unknown RAND command, stop processing

        # Handle commands
        if line.startswith("DELAY "):
            delay_ms = line.split()[1]
            self.output_lines.append(f"    keyboard.delay({delay_ms});")

        elif line.startswith("STRING "):
            text = line[7:]  # Everything after "STRING "
            # Escape special characters
            escaped = text.replace("\\", "\\\\").replace('"', '\\"')
            self.output_lines.append(f'    keyboard.print(F("{escaped}"));')

        elif line.startswith("STRINGLN "):
            text = line[9:]  # Everything after "STRINGLN "
            # Escape special characters
            escaped = text.replace("\\", "\\\\").replace('"', '\\"')
            self.output_lines.append(f'    keyboard.println(F("{escaped}"));')

        elif line == "ENTER":
            self.output_lines.append("    keyboard.sendKeyStroke(KEY_ENTER);")

        elif line.startswith("GUI "):
            key = line.split()[1].upper()
            self.output_lines.append(
                f"    keyboard.sendKeyStroke(KEY_{key}, KEY_MOD_GUI);"
            )

        elif line == "LEFTARROW":
            self.output_lines.append("    keyboard.sendKeyStroke(KEY_LEFT);")

        elif line == "RIGHTARROW":
            self.output_lines.append("    keyboard.sendKeyStroke(KEY_RIGHT);")

        elif line == "UPARROW":
            self.output_lines.append("    keyboard.sendKeyStroke(KEY_UP);")

        elif line == "DOWNARROW":
            self.output_lines.append("    keyboard.sendKeyStroke(KEY_DOWN);")

        elif line == "TAB":
            self.output_lines.append("    keyboard.sendKeyStroke(KEY_TAB);")

        elif line == "ESCAPE":
            self.output_lines.append("    keyboard.sendKeyStroke(KEY_ESC);")

        elif line == "SPACE":
            self.output_lines.append("    keyboard.sendKeyStroke(KEY_SPACE);")

        elif line.startswith("CTRL "):
            parts = line.split()
            if len(parts) >= 2 and parts[1].upper() == "ALT":
                if len(parts) >= 3:
                    final_key = parts[2].upper()
                    self.output_lines.append(
                        f"    keyboard.sendKeyStroke(KEY_{final_key}, KEY_MOD_LCTRL | KEY_MOD_LALT);"
                    )
            else:
                key = parts[1].upper()
                self.output_lines.append(
                    f"    keyboard.sendKeyStroke(KEY_{key}, KEY_MOD_LCTRL);"
                )

        elif line.startswith("ALT "):
            key = line.split()[1].upper()
            self.output_lines.append(
                f"    keyboard.sendKeyStroke(KEY_{key}, KEY_MOD_LALT);"
            )

        elif line.startswith("SHIFT "):
            key = line.split()[1].upper()
            self.output_lines.append(
                f"    keyboard.sendKeyStroke(KEY_{key}, KEY_MOD_LSHIFT);"
            )

    def compile(self, duckyscript_path, output_path):
        """Compile DuckyScript file to C++ main.cpp"""
        # Read DuckyScript
        with open(duckyscript_path, "r", encoding="utf-8") as f:
            lines = f.readlines()

        # Parse all lines
        for line in lines:
            self.parse_line(line)

        # Generate C++ code
        cpp_code = self._generate_cpp()

        # Write output
        with open(output_path, "w", encoding="utf-8") as f:
            f.write(cpp_code)

        print(f"Compiled {duckyscript_path} -> {output_path}")
        print(f"  Language: {self.language}")
        print(f"  Commands: {len(self.output_lines)}")

    def _generate_cpp(self):
        """Generate the complete C++ file"""
        cpp = []
        cpp.append("// Auto-generated from DuckyScript - DO NOT EDIT MANUALLY")
        cpp.append("// Generated by duckyscript_compiler.py")
        cpp.append("")
        cpp.append('#include "attiny85_ducky.h"')
        cpp.append("")
        cpp.append(f"ATTinyDuckyKeyboard keyboard({self.language});")
        cpp.append("")
        cpp.append("int redLED = LED_BUILTIN;")
        cpp.append("")
        cpp.append("void setup() {")
        cpp.append("    pinMode(redLED, OUTPUT);")
        cpp.append("    digitalWrite(redLED, HIGH);")
        cpp.append("")
        cpp.append("    // --- PAYLOAD START ---")

        # Add payload commands
        cpp.extend(self.output_lines)

        cpp.append("    // --- PAYLOAD END ---")
        cpp.append("")
        cpp.append("    digitalWrite(redLED, LOW);")
        cpp.append("}")
        cpp.append("")
        cpp.append("void loop() {")
        cpp.append("    // Empty - payload runs once")
        cpp.append("}")
        cpp.append("")

        return "\n".join(cpp)


def main():
    if len(sys.argv) != 3:
        print("Usage: duckyscript_compiler.py <input.ducky> <output.cpp>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    if not os.path.exists(input_file):
        print(f"Error: Input file not found: {input_file}")
        sys.exit(1)

    compiler = DuckyScriptCompiler()
    compiler.compile(input_file, output_file)


if __name__ == "__main__":
    main()
