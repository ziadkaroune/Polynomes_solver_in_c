# computerv1

Small polynomial equation solver (up to degree 2). It parses a single equation, reduces it to the form $aX^2 + bX + c = 0$, and solves it with the classical algebraic formulas.

## Mathematical method

1. **Move all terms to the left**: the program rewrites the equation by subtracting the right-hand side from the left-hand side, producing a single polynomial equal to zero.
2. **Collect coefficients**: it sums coefficients by degree ($X^0$, $X^1$, $X^2$). Terms with degree $>2$ are rejected.
3. **Reduce form**: the polynomial is printed in reduced form:

$$aX^2 + bX + c = 0$$

4. **Solve by degree**:

- **Degree 0**: $c = 0$ ⇒ any real number is a solution; otherwise no solution.
- **Degree 1**: $aX + b = 0$ ⇒ $X = -\frac{b}{a}$ (if $a \neq 0$).
- **Degree 2**: $aX^2 + bX + c = 0$ uses the discriminant:

$$\Delta = b^2 - 4ac$$

  - $\Delta > 0$: two real solutions
    $$X_{1,2} = \frac{-b \pm \sqrt{\Delta}}{2a}$$
  - $\Delta = 0$: one real double solution
    $$X = \frac{-b}{2a}$$
  - $\Delta < 0$: two complex solutions
    $$X_{1,2} = \frac{-b}{2a} \pm i\,\frac{\sqrt{-\Delta}}{2a}$$

## Build

```zsh
make
```

## Usage

You can pass the equation as an argument or via standard input.

```zsh
./computor "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
```

Or:

```zsh
echo "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0" | ./computor
```

### Accepted format

- Terms like `number * X^power`
- Operators: `+`, `-`, `*`
- One single `=` per equation
- Powers up to `2`

### Example

Input:
```
5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0
```

Reduced form (conceptually):
```
-9.3 * X^2 + 4 * X + 4 = 0
```

Then the solver applies the discriminant method for degree 2.

## Notes

- If the polynomial degree is greater than 2, the program stops with a message indicating it can’t solve it.
- Coefficients are summed by degree after reducing the equation.
