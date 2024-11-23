/*
 * @Author: LetMeFly
 * @Date: 2023-08-24 10:21:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-24 11:46:19
 */
const config = {
    nodes: [
        // {
        //     thisPath: '45649897',
        //     source: 'https://anaer.github.io/Sub/clash.yaml',
        //     description: '不太好用   https://github.com/anaer/Sub  似乎还需要sub.back2me.cn转接一下'
        // },
        // {
        //     thisPath: '7843ljkjsak',
        //     source: 'https://raw.githubusercontent.com/aiboboxx/clashfree/main/clash.yml',
        //     description: '不太好用  https://github.com/aiboboxx/clashfree'
        // },
        // {
        //     thisPath: '9782sjjfejslxh',
        //     source: 'https://raw.githubusercontent.com/tbbatbb/Proxy/master/dist/clash.config.yaml',
        //     description: '不太好用  https://github.com/tbbatbb/Proxy'
        // },
    ]
}

async function handleRequest(request) {
    const requestURL = new URL(request.url)
    const path = requestURL.pathname.split('/')[1];
    // return new Response(path, {
    //     status: 200
    // });

    const nodes = config.nodes;
    for (var i = 0; i < nodes.length; i++) {
        if (nodes[i].thisPath == path) {
            const response = await fetch(nodes[i].source);
            const data = await response.text();
            return new Response(data, {
                status: 200
            });
        }
    }

    return new Response('404', {
        status: 404
    });

    if (location) {
        if (config.no_ref == "on") {
            let no_ref = await fetch("https://xytom.github.io/Url-Shorten-Worker/no-ref.html")
            no_ref = await no_ref.text()
            no_ref = no_ref.replace(/{Replace}/gm, location)
            return new Response(no_ref, {
                headers: {
                    "content-type": "text/html;charset=UTF-8",
                },
            })
        } else {
            return Response.redirect(location, 302)
        }

    }
}

addEventListener("fetch", async event => {
    event.respondWith(handleRequest(event.request))
})