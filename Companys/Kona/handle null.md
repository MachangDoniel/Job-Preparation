Swift solves the **null pointer problem** using a powerful feature called **Optionals**.

---

## ✅ Problem in Traditional Languages (e.g., C/C++, Java)

In many older languages, trying to access a `null` or `nullptr` reference causes a **runtime crash** (e.g., segmentation fault or null pointer exception).

```cpp
string* ptr = nullptr;
cout << ptr->length();  // ❌ CRASH! null pointer dereference
```

---

## ✅ Swift’s Solution: **Optionals**

### 📌 What is an Optional?

An **Optional** in Swift is a type that **might contain a value** or **might be nil**.

```swift
var name: String? = "Alice"  // may contain a String or be nil
```

It’s like wrapping a value in a **safety box** that must be checked/unwrapped before use.

---

## 🧱 How Swift Avoids Null Pointer Errors

### 1. **Compile-Time Safety**

Swift forces you to **explicitly handle Optionals**, so you don’t accidentally dereference `nil`.

```swift
var name: String? = nil
print(name.count)  // ❌ Error: 'String?' does not have member 'count'
```

You **must unwrap** the optional:

### 2. **Optional Binding**

```swift
if let unwrappedName = name {
    print(unwrappedName.count)  // ✅ Safe use
}
```

### 3. **Optional Chaining**

```swift
let length = name?.count  // Returns Int? (nil if name is nil)
```

### 4. **Guard Statement**

```swift
func greet(name: String?) {
    guard let safeName = name else { return }
    print("Hello, \(safeName)")
}
```

### 5. **Nil-Coalescing Operator**

```swift
let username = name ?? "Guest"  // Use "Guest" if name is nil
```

---

## 🚫 What You Can’t Do in Swift

```swift
var name: String? = nil
print(name.count)  // ❌ Compiler Error: must unwrap optional
```

Unlike Java or C++, this would **not compile**, preventing a crash **at compile time** instead of runtime.

---

## ✅ Summary

| Concept                    | Swift Approach                   |
| -------------------------- | -------------------------------- |
| Null pointer               | Replaced with `Optional`         |
| Runtime crash (null deref) | Prevented via compiler checks    |
| Must handle `nil`          | Unwrapping (if-let, guard, `??`) |
| Safety level               | ✅ High — Safe by design          |

---

