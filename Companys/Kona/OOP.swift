class Animal {
    deinit {
        print("OK")
    }
}

class Dog: Animal {
    deinit {
        print("OK 2")
    }
}

func test() {
    let animal: Animal = Dog()
}

test()
// Output:
// OK 2
// OK


// ✅ Where is polymorphism happening here?

// let animal: Animal = Dog()

// Here,

//     Creating an instance of Dog

//     Storing it in a variable typed as Animal

// This is polymorphism, because:

//     The static type is Animal

//     The dynamic type is Dog

// Even though the variable is typed as Animal, it actually refers to a Dog instance — that's the core of polymorphism.
// 🔁 What happens during deinitialization?

// When the Dog instance goes out of scope:

//     Dog.deinit is called — print("OK 2")

//     Then Animal.deinit is called — print("OK")

// ✅ This shows polymorphic behavior at object destruction time as well.