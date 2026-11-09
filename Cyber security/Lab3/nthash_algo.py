import datetime
from passlib.hash import nthash

PASSWORD_FILE = "100k-most-used-passwords-NCSC.txt"
OUTPUT_HASH_FILE = "nthash_output.txt"
SUMMARY_TABLE_FILE = "complexity_summary_table.txt"

def main():
    start_time = datetime.datetime.now()
    print(f"Start Time: {start_time}")

    count = 0
    with open(PASSWORD_FILE, "r", encoding="utf-8", errors="ignore") as infile, \
        open(OUTPUT_HASH_FILE, "w", encoding="utf-8") as outfile:
        
        for line in infile:
            password = line.strip()
            if not password:
                continue
            
            # Hash password
            hashed = nthash.hash(password)
            outfile.write(f"{hashed}\n")
            count += 1

    stop_time = datetime.datetime.now()
    print(f"Stop Time:  {stop_time}")

    elapsed_seconds = (stop_time - start_time).total_seconds()
    time_per_password = elapsed_seconds / count if count > 0 else 0

    print(f"Processed {count} passwords in {elapsed_seconds:.6f} seconds.")
    print(f"Time complexity: {time_per_password:.8f} seconds per password")

    # Format table entry
    table_header = f"{'Algorithm / Parameters':<35} | {'Total Time (s)':<15} | {'Count':<8} | {'Time / Password (s)':<22}\n" + "-" * 88 + "\n"
    table_row = f"{'nthash (entire file)':<35} | {elapsed_seconds:<15.6f} | {count:<8} | {time_per_password:<22.8f}\n"

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

if __name__ == "__main__":
    main()