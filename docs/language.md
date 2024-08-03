## Fibonacci

```fas
// Fibonacci
fn fib(x: int) -> int {
    if x < 3 {
        return 1
    } else {
        return fib(x-1)+fib(x-2)
    }
}

fib(40)
```

## C interop

```fas
extern fn sin(arg: double) -> double
extern fn cos(arg: double) -> double
extern fn atan2(arg: double) -> double

atan2(sin(.4), cos(42))
```