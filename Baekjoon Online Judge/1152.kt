fun main() {
    val sentence = readLine()?.trim()

    if (sentence?.isBlank() != false)
        print(0)
    else
        print(sentence.filter { it == ' ' }.count().plus(1))
}
