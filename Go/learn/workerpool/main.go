package main

import (
	"fmt"
	"sync"
	"time"
)

type Result struct {
	job int
	val int
}

func worker(id int, jobs <-chan int, results chan<- Result, wg *sync.WaitGroup) {
	defer wg.Done()
	for job := range jobs {
		fmt.Printf("[Worker %d] 处理任务 %d\n", id, job)
		time.Sleep(200 * time.Millisecond)
		results <- Result{job: job, val: job * job}
	}
}

func main() {
	const numJobs = 10
	const numWorkers = 3

	jobs := make(chan int, numJobs)
	results := make(chan Result, numJobs)
	var wg sync.WaitGroup

	for w := 1; w <= numWorkers; w++ {
		wg.Add(1)
		go worker(w, jobs, results, &wg)
	}

	for j := 1; j <= numJobs; j++ {
		jobs <- j
	}
	close(jobs)

	go func() {
		wg.Wait()
		close(results)
	}()

	ordered := make([]int, numJobs)

	for result := range results {
		ordered[result.job-1] = result.val
	}

	fmt.Println("结果：")
	for _, result := range ordered {
		fmt.Printf("%d ", result)
	}
	fmt.Println("\n完成。")
}
