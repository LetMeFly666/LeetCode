/*
 * @Author: LetMeFly
 * @Date: 2023-08-28 23:00:58
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-28 23:15:17
 */
/*
 * @Author: LetMeFly
 * @Date: 2023-08-24 10:21:32
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-08-24 11:46:19
 */
const config = {
    hosts: [
        {
            'hostname': 'img-blog.csdnimg.cn',
            'description': 'CSDN IMG'
        }
    ]
}

async function handleRequest(request) {
    const requestURL = new URL(request.url);
    const corsURL = new URL(requestURL.pathname.slice(1));


    const response = await fetch(corsURL);
    // const data = await response.data;
    // return new Response(data, {
    //     status: 200
    // });

    return response;
    return new Response('404', {
        status: 404
    });

}

addEventListener("fetch", async event => {
    event.respondWith(handleRequest(event.request))
})