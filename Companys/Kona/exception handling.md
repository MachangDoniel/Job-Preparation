### 🧩 Exception Handling in Swift

Swift uses a **clean, safe** error-handling model using `do`, `try`, `catch`, and `throw`.

---

## ✅ Key Concepts

| Concept    | Purpose                                                |
| ---------- | ------------------------------------------------------ |
| `throw`    | To **raise** an error                                  |
| `throws`   | Marks a function that **can throw** errors             |
| `try`      | Used to **call** a throwing function                   |
| `do-catch` | Used to **handle** errors thrown inside the `do` block |
| `Error`    | Protocol that defines an error type                    |

---

## 🧪 Example

### 1. Define Error Types

```swift
enum ATMError: Error {
    case insufficientFunds
    case cardBlocked
}
```

---

### 2. Create a Function that Throws

```swift
func withdraw(amount: Int) throws {
    if amount > 1000 {
        throw ATMError.insufficientFunds
    }
    print("Withdrawal successful")
}
```

---

### 3. Handle the Error with `do-try-catch`

```swift
do {
    try withdraw(amount: 1500)
} catch ATMError.insufficientFunds {
    print("❌ Not enough money.")
} catch {
    print("❗️Unknown error: \(error)")
}
```

---

## 🔁 Optional `try?` and `try!`

| Syntax | Meaning                       |
| ------ | ----------------------------- |
| `try?` | Returns `nil` if error thrown |
| `try!` | Crashes if error is thrown    |

```swift
let result = try? withdraw(amount: 2000) // result = nil if error
```

```swift
try! withdraw(amount: 500) // ✅ Fine if no error
```

---

## 🔹 Custom Error with Description

```swift
enum LoginError: Error {
    case invalidUsername
    case invalidPassword
}

func login(user: String, pass: String) throws {
    guard user == "admin" else { throw LoginError.invalidUsername }
    guard pass == "1234" else { throw LoginError.invalidPassword }
}

do {
    try login(user: "admin", pass: "wrong")
} catch LoginError.invalidPassword {
    print("Incorrect password")
}
```

---

## 🧠 Summary

| Feature       | Example                   |
| ------------- | ------------------------- |
| Define Error  | `enum MyError: Error {}`  |
| Throw         | `throw MyError.something` |
| Mark function | `func f() throws {}`      |
| Handle        | `do { try f() } catch {}` |
| Optional Try  | `try?` or `try!`          |
