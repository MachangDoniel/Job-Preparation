**Dependency Injection (DI)** is a **design pattern** used to **pass dependencies** (like objects, services, or data) into a class **from the outside** rather than having the class **create them itself**.

---

## ✅ In Simple Words

Instead of a class saying:

> “I’ll build everything I need.”

It says:

> “Give me what I need.”

---

## 🔧 Why Use Dependency Injection?

* **Looser coupling** between components
* Easier to **test** (you can inject mock objects)
* Promotes **code reuse** and **flexibility**

---

## 🔄 Without vs With Dependency Injection

### ❌ Without DI (Tightly Coupled)

```swift
class Engine {
    func start() {
        print("Engine started")
    }
}

class Car {
    private let engine = Engine() // Car creates its own Engine

    func drive() {
        engine.start()
    }
}
```

* `Car` is tightly coupled with `Engine`
* Harder to test or replace `Engine` with a mock

---

### ✅ With DI (Loosely Coupled)

```swift
class Engine {
    func start() {
        print("Engine started")
    }
}

class Car {
    private let engine: Engine

    init(engine: Engine) {
        self.engine = engine // Engine is injected from outside
    }

    func drive() {
        engine.start()
    }
}
```

Now you can inject:

```swift
let engine = Engine()
let car = Car(engine: engine)
car.drive()
```

Or even mock it for testing:

```swift
class MockEngine: Engine {
    override func start() {
        print("Mock engine started (testing)")
    }
}
```

---

## 🧠 Types of Dependency Injection

| Type                      | Example                                      |
| ------------------------- | -------------------------------------------- |
| **Constructor Injection** | Dependencies passed via initializer          |
| **Property Injection**    | Dependencies set via public properties       |
| **Method Injection**      | Dependencies passed as parameters to methods |

---

## 📱 Real Use in iOS

```swift
class NetworkManager {
    func fetchData() {}
}

class ViewModel {
    let network: NetworkManager

    init(network: NetworkManager) {
        self.network = network
    }
}
```

This makes `ViewModel` **testable**, **flexible**, and **decoupled** from how `NetworkManager` is created.

