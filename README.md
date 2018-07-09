# CodeBreaker
[![pipeline status](https://gitlab.cs.fau.de/en63uroj/CodeBreaker/badges/master/pipeline.svg)](https://gitlab.cs.fau.de/en63uroj/CodeBreaker/commits/master)

CodeBreaker is a very simple Password Cracker that uses MPI to run parallel on HPCs.

# Features

## Hashes

Currently CodeBreaker supports the following hash-formats in regular and linux-crypt mode:

*   MD5 (1)
*   SHA256 (5)
*   SHA512 (6)

### Input Format

The input has to be in the following format:
```
$ALGO$SALT$HASH
```

### Examples
```
MD5(codebreaker): $1$saltsalt$61f4bd2a6a2d9ce9a9c079f2317d46e2
MD5-crypt(codebreaker): $1$saltsalt$.Xn8ZFEBDl5srzZcZHqep.
SHA256(codebreaker): $5$saltsalt$f96762a55b125f8c0bcffff37c0d55e21716cee74592f0c216265733ce617e9c
SHA512(codebreaker): $6$saltsalt$3268ade7fbb34a232e7c486da0d2ec76d782c62494aab28dbf08568c24e21ca6321cefbebff323cc7f253a50d7370f34eaa030e30381dcd778eaef856ee59482
```

## Modes

*   Wordlist only
*   Wordlist + Format-String:
    -   Supported format specifiers: `%s` + `%d`
    -   Example: `%s!_%s?%d.%d"

# Build


```
apt update
cat requirements.txt | xargs sudo apt install
git clone https://github.com/m1ghtym0/CodeBreaker
cd CodeBreaker
make
```

# Usage

```
Usage: src/codebreaker -w wordlist -p passlist [-f format] [-m fmt_str]
-w wordlist: wordlist for word based attack
-p passlist: passlist containing hashes to be cracked
-f format: Specify hash-format of passlist regular, linux-crypt (default: regular)
-m fmt_str: Specify a format string to mangle the wordlist
```

## Examples

```
wget http://ftp.icm.edu.pl/packages/wordlists/names/Given-Names.gz -P /tmp
gunzip /tmp/Given-Names.gz
./hpc/gen_pass_file.sh /tmp/Given-Names 10 md5 /tmp/hashes
mpirun -np 4 ./src/codebreaker -w /tmp/Given-Names -p /tmp/hashes
```
