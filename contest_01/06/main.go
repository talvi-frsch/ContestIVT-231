package main
import "fmt"

func main() {
    var deng int32
    var ost int32
    var pk int32
    var ok int32
    var ps int32
    var ds int32
    var os int32
    
    fmt.Scan(&deng)
    
    pk = deng / 5000
    ost = deng % 5000
    
    ok = ost / 1000
    ost = ost % 1000
    
    ps = ost / 500
    ost = ost % 500
    
    ds = ost / 200
    ost = ost % 200
    
    os = ost / 100
    ost = ost % 100
    
    
    fmt.Println(pk, ok, ps, ds, os)
}
