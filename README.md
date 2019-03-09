# About

Supporting code for the projects of my [NTUA ECE Advanced Computer Architecture 2018 course](http://www.cslab.ece.ntua.gr/courses/advcomparch/2018/info.go).

## pintool_caches

Based on [this pintool](http://www.cslab.ece.ntua.gr/courses/advcomparch/2018/files/askiseis/advanced-ca-Spring-2018-ask1-helpcode.tar.gz), also implements L2 prefetcher functionality.

## pintool_branchpredictors

Based on [this pintool](http://www.cslab.ece.ntua.gr/courses/advcomparch/2018/files/askiseis/advanced-ca-Spring-2018-ask2-helpcode.tar.gz), also implements:
* Static Taken predictor
* Static BTFNT predictor
* Global History predictor
* Local History predictor
* Tournament predictor
* RAS (Return Address Stack)
* BTB (Branch Target Buffer)

Furthermore, stats are reported in a more verbose manner and saved in an output file.

## locks

Based on [this code](http://www.cslab.ece.ntua.gr/courses/advcomparch/2018/files/askiseis/advanced-ca-Spring-2018-ask4-helpcode.tar.gz), implements:
* TAS (test and set) spinlocks using atomic instructions `test_and_set` and `compare_and_swap`
* TTAS (test and test and set) spinlocks using atomic instructions `test_and_set` and `compare_and_swap`


~ Aggelos Kolaitis
