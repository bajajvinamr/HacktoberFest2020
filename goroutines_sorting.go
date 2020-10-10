// package main
//
// import (
//   "fmt"
//   "os"
//   "bufio"
//   "strings"
//   "strconv"
//   "sort"
//   "sync"
// )
//
// func sub_sort(wg *sync.WaitGroup, is []int) {
//   fmt.Println(is)
//   sort.Ints(is)
//   wg.Done()
// }
//
// func main() {
//   fmt.Println("Please input some integers to sort: ")
//   br := bufio.NewReader(os.Stdin)
//   a, _, _ := br.ReadLine()
//   ns := strings.Split(string(a), " ")
//   var numbers []int
//   for _, s := range(ns) {
//     n, _ := strconv.Atoi(s)
//     numbers = append(numbers, n)
//   }
//   size := len(numbers) / 4
//   var wg sync.WaitGroup
//   for c := 0; c < 4; c++ {
//     wg.Add(1)
//     if c != 3 {
//       go sub_sort(&wg, numbers[c*size: (c+1)*size])
//     } else {
//       go sub_sort(&wg, numbers[c*size:])
//     }
//   }
//   wg.Wait()
//
//   var sorted []int
//   c1 := numbers[: 1*size]
//   c2 := numbers[1*size : 2*size]
//   c3 := numbers[2*size : 3*size]
//   c4 := numbers[3*size :]
//   for k := 0; k < len(numbers); k++ {
//     i := 0
//     j := 0
//     if len(c1) !=  0 {
//       i = c1[0]
//       j = 1
//     }
//     if len(c2) != 0 {
//       if j == 0 {
//         i = c2[0]
//         j = 2
//       } else {
//         if c2[0] < i {
//           i = c2[0]
//           j = 2
//           }
//       }
//     }
//     if len(c3) != 0 {
//       if j == 0 {
//         i = c3[0]
//         j = 3
//       } else {
//         if c3[0] < i {
//           i = c3[0]
//           j = 3
//           }
//       }
//     }
//     if len(c4) != 0 {
//       if j == 0 {
//         i = c4[0]
//         j = 4
//       } else {
//         if c4[0] < i {
//           i = c4[0]
//           j = 4
//           }
//       }
//     }
//     sorted = append(sorted, i)
//     switch j {
//     case 1:
//       c1 = c1[1 :]
//     case 2:
//       c2 = c2[1 :]
//     case 3:
//       c3 = c3[1 :]
//     case 4:
//       c4 = c4[1 :]
//     }
//   }
//   fmt.Println(sorted)
// }

// 2nd method

// package main
//
// import (
// 	"bufio"
// 	"fmt"
// 	"math"
// 	"os"
// 	"sort"
// 	"strconv"
// 	"strings"
// 	"sync"
// )
//
// func main() {
// 	fmt.Print("input a series of integers split by space \n--RK--> ")
//
// 	reader := bufio.NewReader(os.Stdin)
// 	input, _ := reader.ReadString('\n')
//
// 	s := strings.Split(strings.TrimSpace(input), " ")
// 	a := make([]int, 0, len(s))
//
// 	// converting to integer
// 	for _, str := range s {
// 		num, _ := strconv.Atoi(str)
// 		a = append(a, num)
// 	}
//
// 	const par = 4
// 	n := int(math.Max(math.Ceil(float64(len(s))/float64(par)), 1))
//
// 	// a wait group to synchronize all goroutines
// 	var w sync.WaitGroup
//
// 	// partition the given array to approximately equal size
// 	for i := 0; i < par; i++ {
// 		from := int(math.Min(float64(i*n), float64(len(a))))
// 		to := int(math.Min(float64((i+1)*n), float64(len(a))))
//
// 		w.Add(1)
//
// 		go func(arr []int) {
// 			fmt.Println("will sort: ", arr)
// 			sort.Ints(arr)
//
// 			w.Done()
// 		}(a[from:to])
// 	}
//
// 	// wait for all goroutines finished
// 	w.Wait()
//
// 	sort.Ints(a)
// 	fmt.Println("sorted: ", a)
// }


//3rd method

package main

import (
    "fmt"
    "bufio"
    "os"
    "strings"
    "sort"
    "sync"
    "strconv"
)

const number_of_sorters = 4

func sortpart(i int, numbers []int, wg *sync.WaitGroup) {
    fmt.Printf("goroutine %d sorting: %v\n", i, numbers)
    sort.Ints(numbers)
    wg.Done()
}

func pop_min(slices [][]int) ([][]int, int) {
    // find the smallest first element of the given slices, delete it
    // if the chosen slice is empty it is deleted from the source.
    // returns New slice of slices and the lowest value found

    // find the value and index if the lowest first element
    min_val := slices[0][0]
    min_val_slice_j := 0
    for j := 1; j < len(slices); j++ {
        if slices[j][0] < min_val {
            min_val = slices[j][0]
            min_val_slice_j  = j
        }
    }

    // delete the element from the slice
    slices[min_val_slice_j] = slices[min_val_slice_j][1:]

    // if the slice is empty, delete the slice from the given slices
    if len(slices[min_val_slice_j]) <= 0 {
        slices = append(slices[:min_val_slice_j], slices[min_val_slice_j + 1:]...)
    }

    return slices, min_val
}

func main() {
    fmt.Printf("Please enter a series of integers separated by a space: ")
	scan := bufio.NewScanner(os.Stdin)
	scan.Scan()
    anums := strings.Fields(scan.Text())

    // slice of slices being passed to the sorters
    slices := make([][]int, 0, number_of_sorters)

    var wg sync.WaitGroup

    nremaining := len(anums)
    offset := 0

    // iterate through the sorters assigning them a slick
    for i := 0; i < number_of_sorters && nremaining > 0; i++ {
        // n is the sice of this sorter's slice
        n := (nremaining - 1) / (number_of_sorters - i) + 1
        nremaining = nremaining - n

        // create the slice and add the ints
        slices = append(slices, make([]int, n))
        for j := 0; j < n; j++ {
            ival, _ := strconv.Atoi(anums[j + offset])
            slices[i][j] = ival
        }

        wg.Add(1)
        go sortpart(i, slices[i], &wg)
        offset = offset + n
    }

    wg.Wait()

    sorted := make([]int, len(anums))

    // now slices contains sorted slices
    // we build the array by popping the smallest first elemnt of our sorted slices
    // until we have the array
    for i := range sorted {
        // assign the next lowest element
        slices, sorted[i] = pop_min(slices)

    }
    fmt.Printf("Sorted: %v\n", sorted)
}
