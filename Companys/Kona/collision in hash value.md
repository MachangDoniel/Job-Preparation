If **two different keys return the same hash value**, this situation is known as a **hash collision**.

---

## 💥 What is a Hash Collision?

A **hash collision** occurs when **two different keys** produce the **same hash value** in a hash table or hash map.

```plaintext
hash("apple") = 5
hash("peach") = 5   ← Collision!
```

---

## 🛠 How to Handle Hash Collisions?

There are several **collision resolution techniques**. The most common are:

---

### 1. **Chaining (Separate Chaining)**

* Store multiple values in a **list (linked list or array)** at the same index.

```plaintext
hash(apple) → index 5 → [apple]
hash(peach) → index 5 → [apple, peach]
```

#### Code Example in C++-like logic:

```cpp
unordered_map<int, list<pair<string, string>>> hashTable;

int index = hash(key) % size;
hashTable[index].push_back({key, value});
```

---

### 2. **Open Addressing**

* If a collision happens, search for the next available index.

#### Techniques:

| Method             | Description                                  |
| ------------------ | -------------------------------------------- |
| **Linear Probing** | Check next slot: `(index + 1) % size`        |
| **Quadratic**      | Check: `(index + i^2) % size`                |
| **Double Hashing** | Use a second hash function to find new index |

#### Example (Linear Probing):

```plaintext
hash(peach) = 5 → occupied
try index 6 → empty → insert
```

---

### 3. **Use a Better Hash Function**

* Ensure the **hash function distributes values uniformly**.
* Avoid simple or predictable functions (e.g., `sum of ASCII values`).

---

### 4. **Using Trees (Modern Maps)**

Languages like Java and C++ use a **balanced binary search tree** at each bucket when too many collisions occur (like in `std::unordered_map` or Java's `HashMap`).

---

## 📦 In Swift?

Swift’s `Dictionary` internally uses **open addressing with linear probing**, and handles collisions efficiently behind the scenes.

You don't usually need to worry unless you're creating your own hash table.

But you **must implement `hash(into:)` and `==`** if you're using a custom key:

```swift
struct Person: Hashable {
    let id: Int
    let name: String

    func hash(into hasher: inout Hasher) {
        hasher.combine(id)
    }

    static func == (lhs: Person, rhs: Person) -> Bool {
        return lhs.id == rhs.id
    }
}
```

If two objects have the same hash but are **not equal**, Swift will still keep them separate correctly.

---

## ✅ Summary

| Method           | Description                               |
| ---------------- | ----------------------------------------- |
| Chaining         | Store multiple items in a list per bucket |
| Open Addressing  | Find next empty slot                      |
| Better Hash Func | Reduce collisions from the start          |
| Use Trees        | Efficient lookup for collided buckets     |

