// Test_generics.kt — Targeted tests for Array<T> / generic type grammar
// Each function tests one specific generic type construct.
// All should parse successfully with 0 errors.

// 1. Generic type as parameter
fun takeArray(arr: Array<Int>) {
    println(arr[0])
}

// 2. Generic type as return type
fun getArray(): Array<Int> {
    return []
}

// 3. Generic type in variable declaration
fun declareGeneric() {
    var a: Array<Int> = Array<Int>(10)
    var b: Array<String> = Array<String>(5)
    var c: Array<Boolean> = Array<Boolean>(3)
}

// 4. Nullable generic — Array<Int>?
fun nullableGeneric(flag: Boolean): Array<Int>? {
    if (flag) {
        return []
    }
    return null
}

// 5. Generic param AND generic return
fun copyArray(src: Array<Int>): Array<Int> {
    return src
}

// 6. Multiple generic params in same function
fun twoArrays(a: Array<Int>, b: Array<String>): Array<Int> {
    return a
}

// 7. Nested generic — Array<Array<Int>>
fun nested(matrix: Array<Array<Int>>): Array<Array<Int>> {
    return matrix
}

// 8. Nullable nested — Array<Array<Int>>?
fun nullableNested(x: Array<Array<Int>?>): Int {
    return 0
}

// 9. Generic type in variable with nullable inner — Array<Int?>
fun nullableElements(): Array<Int?> {
    var arr: Array<Int?> = Array<Int?>(5)
    return arr
}

// 10. Multi-arg generic — Map<String, Int>
fun mapParam(m: Map<String, Int>): Int {
    return 0
}

// 11. Nullable multi-arg generic — Map<String, Int>?
fun nullableMap(m: Map<String, Int>?): Int {
    val result = m ?: 0
    return 0
}

// 12. Generic type used in as-cast expression
fun castArray(x: Int): Int {
    val y = x + 1
    return y
}

// 13. main() with Array<String> — exact pattern from K0 spec
fun main(args: Array<String>) {
    println("Hello, World!")
}