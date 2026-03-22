# 🏧 ATM Simulation Program (C)

A console-based ATM (Automated Teller Machine) simulation written in C that supports multilingual menus, PIN authentication, and core banking operations.

---

## Features

- **Multilingual Support** — Choose from English, Telugu (తెలుగు), or Hindi (हिंदी) at startup
- **PIN Authentication** — 4-digit PIN with a maximum of 3 attempts before lockout
- **Check Balance** — View the current account balance
- **Cash Deposit** — Deposit funds (minimum ₹100)
- **Cash Withdrawal** — Withdraw funds with balance and minimum amount validation
- **Session Loop** — Continue transactions until you choose to exit

---

## Getting Started

### Prerequisites

- A C compiler such as **GCC** or **Clang**

### Compilation

```bash
gcc atm.c -o atm
```

### Run

```bash
./atm
```

---

## Usage

### Step 1 — Select Language

```
------Welcome To Our ATM------
Please Select Your Language
1. English
2. Telugu
3. Hindi
Enter Your Language :- 
```

> If an invalid option is entered, English is selected by default.

### Step 2 — Enter PIN

```
Enter your 4-digit PIN: 
```

- The correct PIN is required to proceed.
- After **3 failed attempts**, the program exits automatically.

### Step 3 — Perform Transactions

Once authenticated, the main menu is displayed in your chosen language:

```
1. Check Balance
2. Cash Deposit
3. Cash Withdraw
4. Exit
```

---

## Transaction Rules

| Operation   | Rule                                      |
|-------------|-------------------------------------------|
| Deposit     | Minimum deposit amount is ₹100            |
| Withdrawal  | Minimum withdrawal amount is ₹100         |
| Withdrawal  | Cannot exceed available balance           |
| PIN entry   | Locked out after 3 consecutive failures   |

---

## Default Values

| Setting         | Value      |
|-----------------|------------|
| Starting Balance| ₹1000.00   |
| ATM PIN         | `1735`     |
| Max PIN Attempts| 3          |

> ⚠️ **Note:** The PIN is hardcoded as a `#define` constant in the source file. For real-world use, this must be replaced with a secure authentication mechanism.

---

## Project Structure

```
atm.c       # Main source file containing all program logic
README.md   # Project documentation
```

---

## Limitations & Future Improvements

- PIN is hardcoded — should use secure storage or hashing in production
- Single account only — no multi-user or database support
- Balance resets every session — no persistent storage
- No transaction history or receipt generation
- Input validation is basic (no protection against non-numeric input)

---

## License

This project is intended for educational purposes. Feel free to modify and extend it.
