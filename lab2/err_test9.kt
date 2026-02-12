fun main() {
    // Make sure these don't get confused
    val a = 5 + ++x        // + followed by ++
    val b = x+++y          // ++ followed by +
    val c = x<y&&z>w       // < and > mixed with &&
    val d = x?.y?:z        // ?. followed by ?:
}