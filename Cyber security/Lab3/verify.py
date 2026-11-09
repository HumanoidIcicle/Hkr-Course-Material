import datetime
from passlib.hash import argon2, sha512_crypt, nthash

SUMMARY_TABLE_FILE = "verification_summary.txt"

def verify_hash(algo, algo_label, hashed_file):
    start_time = datetime.datetime.now()
    print(f"\nStart Time: {start_time}")
    count = 0

    with open(hashed_file, "r", encoding="utf-8") as infile, \
        open("100k-most-used-passwords-NCSC.txt", "r", encoding="utf-8") as password_file:
        for hashed_line, password_line in zip(infile, password_file):
            hashed_password = hashed_line.strip()
            original_password = password_line.strip()

            if not hashed_password or not original_password:
                continue
            
            # Verify the password
            is_correct = algo.verify(original_password, hashed_password)
            print(f"Password: {original_password}, Verification result: {is_correct}")
            count += 1
    
    stop_time = datetime.datetime.now()
    print(f"Stop Time:  {stop_time}")

    elapsed_seconds = (stop_time - start_time).total_seconds()
    time_per_password = elapsed_seconds / count if count > 0 else 0

    print(f"Processed {count} passwords in {elapsed_seconds:.6f} seconds.")
    print(f"Time complexity: {time_per_password:.8f} seconds per password.\n")

    # Format table entry
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
    # Verify NT hashes
    verify_hash(nthash, "nthash (entire file)", "nthash_output.txt")

    # Verify Argon2 hashes
    verify_hash(argon2, "argon2 (M=65536, rounds=2)", "argon2_M65536_R2_output.txt")
    verify_hash(argon2, "argon2 (M=65536, rounds=3)", "argon2_M65536_R3_output.txt")
    verify_hash(argon2, "argon2 (M=65536, rounds=4)", "argon2_M65536_R4_output.txt")
    verify_hash(argon2, "argon2 (M=32768, rounds=3)", "argon2_M32768_R3_output.txt")
    verify_hash(argon2, "argon2 (M=131072, rounds=3)", "argon2_M131072_R3_output.txt")

    # Verify SHA512 hashes
    verify_hash(sha512_crypt, "sha512_crypt (rounds=328000)", "sha512_328000_output.txt")
    verify_hash(sha512_crypt, "sha512_crypt (rounds=656000)", "sha512_656000_output.txt")
    verify_hash(sha512_crypt, "sha512_crypt (rounds=1312000)", "sha512_1312000_output.txt")

if __name__ == "__main__":
    main()