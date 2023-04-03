const longRunningTask = () => {
    return new Promise(resolve => {
        setTimeout(() => {
            resolve(Math.floor(Math.random() * Math.floor(100)))
        }, 3000)
    })
}

async function thread() {
    const r = await longRunningTask()
    console.log(r.toString() + " " + new Date().toString())
} 


async function main() {
    thread()
    let a = 0
    while (true) {
        console.log((a++).toString() + " | " + new Date())
        const delay = ms => new Promise(resolve => setTimeout(resolve, ms))
        await delay(1000)
    }
}

main()
