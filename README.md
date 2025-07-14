# 📓 Personal Diary Record Manager (C Project)

This is a simple command-line diary application written in **C** that allows users to **add**, **edit**, **delete**, and **password-protect** their personal records. It also features basic **encryption** to secure diary entries stored as files on disk.

---

## 🔧 Features

* 🔐 **Password Protection**
  Access to editing and deletion is guarded by a user-defined password.

* 📝 **Edit Records**
  Modify existing records by date and time. Choose to update:

  * Time
  * Place
  * Note
  * Exit Time
  * Entire record

* 🗑️ **Delete Records**
  Remove:

  * Entire record files by date
  * Specific entries by time within a file

* 🔒 **Simple Encryption/Decryption**
  Records are encrypted using a basic character-shift cipher to obfuscate contents in the saved file.

---

## 📁 File Structure

* Each day's entries are saved in a file named with the date:
  Example: `13-07-2025`

* Encrypted temporary files are created during encryption/decryption:

  * `SecurityTemporary.txt`

* Password is stored in:

  * `SE` (binary file with basic offset encryption)

---

## ⚠️ Important Notes

* **Insecure Encryption**: The current encryption algorithm adds/subtracts `100` from each character. This is easily reversible and not suitable for sensitive data.
* **Unsafe Functions**: The program uses deprecated functions like `gets()` and `fflush(stdin)` which are unsafe. Consider replacing them with `fgets()` and safer input handling.
* **Compatibility**: Built for C compilers like **Turbo C** or **GCC**. Some parts may require slight adaptation on modern systems.

---

## 🚀 How to Compile

You can compile the code using any standard C compiler.

### On GCC (Linux/Windows via MinGW):

```bash
gcc -o diary diary.c
./diary
```

---

## 📦 Future Improvements

* Replace `gets()` with `fgets()` for safety.
* Use hashing (e.g., SHA-256) for password storage.
* Improve encryption using standard algorithms (AES, etc.).
* GUI version with Qt or GTK.
* Use a database (like SQLite) for storage instead of file-based entries.

---

## 👤 Author

This project was written as a basic file-handling and security demonstration in C.
Feel free to use and expand it for educational purposes.

---
