/*
 * @Author: LetMeFly
 * @Date: 2026-08-10 21:17:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-08-10 22:32:01
 */
package main

import "github.com/gin-gonic/gin"

func a(c *gin.Context) {
	c.JSON(200, gin.H{
		"from": "a",
	})
}

func b(c *gin.Context) {
	c.JSON(200, gin.H{
		"from": "b",
	})
}

func aWithAbort(c *gin.Context) {
	c.JSON(200, gin.H{
		"from": "aAbort",
	})
	c.Abort()
	c.JSON(200, gin.H{
		"from": "aAbort2",
	})
}

func next(c *gin.Context) {
	c.JSON(200, gin.H{
		"from": "next.before",
	})
	c.Next()
	c.JSON(500, gin.H{
		"from": "next.after",
	})
}

func aAbortAndNext(c *gin.Context) {
	c.JSON(404, gin.H{
		"from": "aAbortAndNext",
	})
	c.Abort()
	c.Next()
	c.JSON(200, gin.H{
		"from": "aAbortAndNext2",
	})
}


func main() {
	c := gin.Default()
	c.GET("/1", a, b)              // {"from":"a"}{"from":"b"} 不难发现handler a并没有c.Next()
	c.GET("/2", aWithAbort, b)     // {"from":"aAbort"}{"from":"aAbort2"} 不执行b了但执行了a后续
	c.GET("/3", next, b)           // {"from":"next.before"}{"from":"b"}{"from":"next.after"}     (200)
	c.GET("/4", aAbortAndNext, b)  // {"from":"aAbortAndNext"}{"from":"aAbortAndNext2"}           (404)
	c.Run()
}
