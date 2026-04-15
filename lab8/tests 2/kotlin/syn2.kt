fun namedArg() {
    val r = add(x = 1, y = 2)
    println(r)
}

fun add(x: Int, y: Int): Int {
    return x + y
}
