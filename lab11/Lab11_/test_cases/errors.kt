// hw5_errors.kt -- one of each expected semantic error
// DO NOT run this whole file -- copy each function into its own .kt file
// Each function contains exactly ONE semantic error.

// ── ERROR 1: assignment to val (immutability) ──────────────────────────────
// File: err_immutable.kt
fun err_immutable() {
    val x = 5
    x = 10
}
// Expected: error: assignment to immutable variable 'x' (declared as val)

// ── ERROR 2: assignment to const val ──────────────────────────────────────
// File: err_const.kt
const val MAX = 100
fun err_const() {
    MAX = 200
}
// Expected: error: assignment to immutable variable 'MAX' (declared as const val)

// ── ERROR 3: type mismatch in declaration ─────────────────────────────────
// File: err_type_decl.kt
fun err_type_decl() {
    val x: Int = true
}
// Expected: error: type mismatch in declaration of 'x': expected int, got bool

// ── ERROR 4: null assigned to non-nullable ────────────────────────────────
// File: err_null.kt
fun err_null() {
    val x: Int = null
}
// Expected: error: null cannot be assigned to non-nullable 'x'

// ── ERROR 5: arithmetic on non-numeric ────────────────────────────────────
// File: err_arith.kt
fun err_arith() {
    val a = true
    val b = true
    val c = a + b
}
// Expected: error: non-numeric left operand (bool) in arithmetic

// ── ERROR 6: logical operator on non-boolean ──────────────────────────────
// File: err_logical.kt
fun err_logical() {
    val x = 5
    val y = 10
    val z = x && y
}
// Expected: error: non-boolean operand in logical expression

// ── ERROR 7: NOT on non-boolean ───────────────────────────────────────────
// File: err_not.kt
fun err_not() {
    val x = 42
    val y = !x
}
// Expected: error: non-boolean operand for '!' operator

// ── ERROR 8: redeclaration ────────────────────────────────────────────────
// File: err_redecl.kt
fun err_redecl() {
    val x = 5
    val x = 10
}
// Expected: error: redeclaration of 'x'

// ── ERROR 9: assignment type mismatch ────────────────────────────────────
// File: err_assign_type.kt
fun err_assign_type() {
    var x: Int = 5
    x = true
}
// Expected: error: type mismatch in assignment to 'x': expected int, got bool

// ── ERROR 10: null assigned to non-nullable via reassignment ──────────────
// File: err_null_assign.kt
fun err_null_assign() {
    var x: Int = 5
    x = null
}
// Expected: error: null cannot be assigned to non-nullable 'x'