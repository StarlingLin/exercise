package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
)

type Response struct {
	Code    int    `json:"code"`
	Message string `json:"message"`
	Data    any    `json:"data,omitempty"`
}

func myHandler(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodGet {
		http.Error(w, "仅支持GET", http.StatusMethodNotAllowed)
		return
	}
	name := r.URL.Query().Get("name")
	if name == "" {
		name = "default"
	}
	resp := Response{
		Code:    200,
		Message: fmt.Sprintf("你好，%s。", name),
	}
	w.Header().Set("Content-Type", "application/json; charset=utf-8")
	json.NewEncoder(w).Encode(resp)
}

func main() {
	http.HandleFunc("/test", myHandler)
	addr := "127.0.0.1:18080"
	fmt.Printf("启动，监听地址：http://%s\n", addr)
	fmt.Printf("访问示例：http://%s/test?name=Starling\n", addr)
	log.Fatal(http.ListenAndServe(addr, nil))
}
