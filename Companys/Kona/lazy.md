## 🐢 `lazy` in Swift

> A `lazy` property is **not initialized** until the **first time it is accessed**. It’s perfect when initialization is **expensive** or **not always needed**.

---

### ✅ Syntax

```swift
class DataManager {
    lazy var data: [String] = {
        print("Data initialized")
        return ["One", "Two", "Three"]
    }()
}
```

---

### 💡 Example

```swift
let manager = DataManager()
// At this point, `data` is not yet initialized.

print(manager.data) // Now it's initialized and prints: ["One", "Two", "Three"]
```

🖨 Output:

```
Data initialized
["One", "Two", "Three"]
```

---

## 🧠 When to Use `lazy`

* When the property’s **initialization is costly**
* When it **might not be used at all**
* When it depends on **self** (like closures using `self` inside a class)

---

⚠️ **Note:**

* `lazy` only works with **var**, not `let`.
* Not allowed in `structs` if the instance is a constant.

