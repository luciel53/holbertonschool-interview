import sys
import re

# Initialize variables
total_size = 0
status_code_counts = {}
line_count = 0

try:
    for line in sys.stdin:
        line = line.strip()

        # Parse the input line using regular expression
        match = re.match(r'^\d+\.\d+\.\d+\.\d+ - \[.*\] "GET \/projects\/260 HTTP\/1\.1" (\d+) (\d+)$', line)

        if match:
            status_code, file_size = map(int, match.groups())

            # Update total file size
            total_size += file_size

            # Update status code counts
            if status_code in status_code_counts:
                status_code_counts[status_code] += 1
            else:
                status_code_counts[status_code] = 1

            # Increment line count
            line_count += 1

            # Check if we have processed 10 lines
            if line_count % 10 == 0:
                print("Total file size:", total_size)
                for code in sorted(status_code_counts.keys()):
                    print(f"{code}: {status_code_counts[code]}")

except KeyboardInterrupt:
    # Handle keyboard interruption (CTRL + C)
    print("Total file size:", total_size)
    for code in sorted(status_code_counts.keys()):
        print(f"{code}: {status_code_counts[code]}")
