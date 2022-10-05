proc getAlphabet(): string =
  var accm = ""
  for letter in 'a'..'z':  # see iterators
    accm.add(letter)
  return accm

# Computed at compilation time
const alphabet = getAlphabet()

# Mutable variables
var
  a = "foo"
  b = 0
  # Works fine, initialized to 0
  c: int

# Immutable variables
let
  d = "foo"
  e = 5
  # Compile-time error, must be initialized at creation
  f: float

# Works fine, `a` is mutable
a.add("bar")
b += 1
c = 3

# Compile-time error, const cannot be modified at run-time
alphabet = "abc"

# Compile-time error, `d` and `e` are immutable
d.add("bar")
e += 1