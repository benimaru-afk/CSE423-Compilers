fun nullable(x: Int?) {
    val y = x ?: 0
    val z = x?.toString()
    println(y)
    println(z)
}
