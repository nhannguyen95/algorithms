Avoid noise words:
- `Product` is indistinguishable from `ProductInfo` or `ProductData`.
- Same for `moneyAmount` and `money`, `theMessage` and `message`.

---

Use pronounceable names: avoid names like `genymdhms`, `DtaRcrd102`.

It makes you sound like an idiot when explaining your code.

---

Single-letter names should ONLY be used as local variables inside short methods.

The length of a name should correspond to the size of its scope.

---

A class name should be a noun, not a verb: `Customer`, `WikiPage`, `Account`...

Avoid words like `Manager`, `Processor`, `Data` or `Info` in the name of a class.

---

Accessors, mutators, and predicates (methods that return true or false) should be named for their value and prefixed with `get`, `set` and `is`:
- Accessors: `getName`.
- Mutators: `setName`.
- Predicates: `isPosted`.

---

Pick one word for one abstract concept and stick with it. For instance, it’s confusing to have `fetch`, `retrieve`, and `get` as equivalent methods of different classes.
