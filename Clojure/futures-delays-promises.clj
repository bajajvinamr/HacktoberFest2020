Clojure futures, delays and promises in Action

;; Futures
;; futures define a task and place it on another
;; thread without requiring the result immediately
(do
  (future (Thread/sleep 4000)
          (println "I will print after 4 seconds"))
  (println "I will print imediately"))

;; The future function returns a reference value that you can use to request the result
;; A future’s body executes only once, and its value gets cached.
;; Futures are a dead-simple way to sprinkle some concurrency on your program.
(def sym (future (Thread/sleep 4000)
                 (inc 2)
                 [1 2 3 4 5]))
sym
;; => #future[{:status :pending, :val nil} 0x1c57399]

;; after 4 seconds
sym
;; => #future[{:status :ready, :val [1 2 3 4 5]} 0x1c57399]


;; Delay
;; Delays allow you to define a task without having to execute it or require the result immediately.

(def jackson-5-delay
  (delay (let [message "Just call my name and I will be there"]
           (println "First deref:" message)
           message)))
(force jackson-5-delay)
;; => First deref: Just call my name and I will be there
;;    "Just call my name and I will be there"

(force jackson-5-delay)
;; => "Just call my name and I will be there"
;; Like futures, a delay is run only once and its result is cached



;; Promises
;; Promises allow you to express that you expect a result without having to
;; define the task that should produce it or when that task should run.

(def my-promise (promise))
(deliver my-promise (+ 1 3))
;; => #promise[{:status :ready, :val 4} 0x8091d10]
@my-promise
;; => 4

;; You can only deliver a result to a promise once.
(deliver my-promise (+ 1 1110000))
;; => nil
