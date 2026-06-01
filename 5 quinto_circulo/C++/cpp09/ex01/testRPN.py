#!/usr/bin/env python3
import subprocess

tests = [
    ("", "Error"),
    ("8", "8"),
    ("8 9", "Error"),
    ("8 9 +", "17"),
    ("8 9 *", "72"),
    ("8 9 * 9 - 9 - 9 - 4 - 1 +", "42"),
    ("8 0 /", "Error"),
    ("a b +", "Error"),
    ("10 2 +", "Error"),
    ("9 1 -", "8"),
    ("2 3 /", "0"),
    ("8 7 6 9 + + +", "30"),
    ("8 7 6", "Error"),
    ("1 2 + 3 *", "9"),
    ("1 2 + 3", "Error"),
    ("9 1 - 2 /", "4"),
    ("4 0 /", "Error"),
    ("+", "Error"),
    ("1 + 2", "Error"),
    ("1 2 + +", "Error"),
    ("1 2 3 +", "Error"),
    ("   8 9 +   ", "17"),
]

ok_count = 0
nok_count = 0

for expr, expected in tests:
    result = subprocess.run(
        ["./RPN", expr],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )

    actual = result.stdout.strip() if result.stdout.strip() else result.stderr.strip()
    status = "OK" if actual == expected else "NOK"

    if status == "OK":
        ok_count += 1
    else:
        nok_count += 1

    print(f'Input: "{expr}" | Expected: {expected} | Actual: {actual} | {status}')

print(f"\nOK: {ok_count}")
print(f"NOK: {nok_count}")
print(f"TOTAL: {len(tests)}")