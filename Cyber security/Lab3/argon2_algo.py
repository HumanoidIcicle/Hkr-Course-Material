import datetime
from passlib.hash import argon2

PASSWORD_FILE = "100k-most-used-passwords-NCSC.txt"
OUTPUT_HASH_FILE = "output_argon2.txt"
SUMMARY_TABLE_FILE = "complexity_summary_table.txt"
MAX_PASSWORDS = 500

def argon2_hash(OUTPUT_HASH_FILE, MEMORY_COST_KIB, ROUNDS):
    # Passlib argon2 configuration: memory_cost is specified in KiB
    hasher = argon2.using(memory_cost=MEMORY_COST_KIB, rounds=ROUNDS)

    start_time = datetime.datetime.now()
    print(f"\nStart Time: {start_time}")

    count = 0
    with open(PASSWORD_FILE, "r", encoding="utf-8", errors="ignore") as infile, \
        open(OUTPUT_HASH_FILE, "w", encoding="utf-8") as outfile:
        for line in infile:
            if count >= MAX_PASSWORDS:
                break
            password = line.strip()
            if not password:
                continue
            
            # Hash password with M, rounds
            hashed = hasher.hash(password)
            print(f"Hashed password: {password}")
            outfile.write(f"{hashed}\n")
            count += 1

    stop_time = datetime.datetime.now()
    print(f"Stop Time:  {stop_time}")

    elapsed_seconds = (stop_time - start_time).total_seconds()
    time_per_password = elapsed_seconds / count if count > 0 else 0

    print(f"Processed {count} passwords in {elapsed_seconds:.6f} seconds.")
    print(f"Time complexity: {time_per_password:.8f} seconds per password.\n")

    # Format table entry
    algo_label = f"argon2 (M={MEMORY_COST_KIB}, rounds={ROUNDS})"
    table_header = f"{'Algorithm / Parameters':<35} | {'Total Time (s)':<15} | {'Count':<8} | {'Time / Password (s)':<22}\n" + "-" * 88 + "\n"
    table_row = f"{algo_label:<35} | {elapsed_seconds:<15.6f} | {count:<8} | {time_per_password:<22.8f}\n"

    # Save to summary text file
    try:
        with open(SUMMARY_TABLE_FILE, "r") as f:
            content = f.read()
    except FileNotFoundError:
        content = ""

    with open(SUMMARY_TABLE_FILE, "a", encoding="utf-8") as summary_file:
        if "Algorithm / Parameters" not in content:
            summary_file.write(table_header)
        summary_file.write(table_row)

def main():
    argon2_hash("argon2_M65536_R2_output.txt", 65536, 2)
    argon2_hash("argon2_M65536_R3_output.txt", 65536, 3)
    argon2_hash("argon2_M65536_R4_output.txt", 65536, 4)
    argon2_hash("argon2_M32768_R3_output.txt", 32768, 3)
    argon2_hash("argon2_M131072_R3_output.txt", 131072, 3)

if __name__ == "__main__":
    main()