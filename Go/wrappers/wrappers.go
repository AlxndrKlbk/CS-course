package main

import(
    "fmt"
    "time"
    "runtime"
    "reflect"
)

func countCall(f func(string)) func(string) {
    cnt := 0
    // получаем имя функции. Подробнее об этом вызове будет рассказано в следующем курсе
    funcname := runtime.FuncForPC(reflect.ValueOf(f).Pointer()).Name()
    return func(s string) {
        cnt++
        fmt.Printf("Функция %s вызвана %d раз\n", funcname, cnt)
        f(s)
    }
}

// metricTimeCall — функция-обёртка для замера времени
func metricTimeCall(f func(string)) func(string) {
    return func(s string) {
        start := time.Now() // получаем текущее время
        f(s)
        fmt.Println("Execution time: ", time.Now().Sub(start)) // получаем интервал времени как разницу между двумя временными метками
    }
}

func myprint(s string) {
    fmt.Println(s)
}

func main() {

    countedPrint := countCall(myprint)
    countedPrint("Hello world")
    countedPrint("Hi")

    // обратите внимание, что мы оборачиваем уже обёрнутую функцию, а значение счётчика вызовов при этом сохраняется
    countAndMetricPrint := metricTimeCall(countedPrint)
    countAndMetricPrint("Hello")
    countAndMetricPrint("World")

}