/*
 * @Author: LetMeFly
 * @Date: 2023-01-18 13:50:06
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-01-19 10:59:45
 */
$().ready(function() {
    const footer = $("#footer-info");
    const originalFooterHTML = footer.html();
    var originalYear = "";
    for (var i = originalFooterHTML.indexOf("© ") + 2; ; i++) {
        if (originalFooterHTML[i] >= '0' && originalFooterHTML[i] <= '9') {
            originalYear += originalFooterHTML[i];
        }
        else {
            break;
        }
    }  // 其实可以直接修改 ToCopy/themes/landscape/layout/_partial/footer.ejs
    var newFooterHTML = "<div style='display: inline-block;'>© 2022 - " + originalYear + " <a href='https://letmefly.xyz' target='_blank'>LetMeFly</a><br> Powered by <a href='http://hexo.io/' target='_blank'>Hexo</a></div><div style='display: inline-block;'>";
    function judgeIfIndexAndReturnTheNewURLParameter() {  // 返回：[布尔类型的是否是首页, 若不是首页则访客量统计图片的地址的参数]
        var href = location.href;
        const indexOfDoubleZUOXIEXIAN = href.indexOf("//");
        href = href.substring(indexOfDoubleZUOXIEXIAN + 2);
        const indexOfFirstSingleZUOXIEXIAN = href.indexOf("/");
        var parameter = "LetMeFly-LeetCodeBlog";
        if (indexOfFirstSingleZUOXIEXIAN == -1 || indexOfFirstSingleZUOXIEXIAN == href.length - 1 || href[indexOfFirstSingleZUOXIEXIAN + 1] == '?') {
            return [true, parameter];
        }
        else {
            href = href.substring(indexOfFirstSingleZUOXIEXIAN + 1);
            if (href.indexOf("?") != -1) {
                href = href.substring(0, href.indexOf("?"));
            }
            const splited = href.split("/");
            for (var i = 0; i < splited.length; i++) {
                if (splited[i]) {
                    parameter += "230119" + splited[i];
                }
            }
            return [false, parameter];
        }
    }
    const ifIndexResult = judgeIfIndexAndReturnTheNewURLParameter();
    if (ifIndexResult[0]) {
        newFooterHTML += "本站总"
    }
    else {
        newFooterHTML += "本页"
    }
    newFooterHTML += "访问量(From 2022-1-19)：<img src='https://profile-counter.glitch.me/" + ifIndexResult[1] + "/count.svg'></img>";
    if (!ifIndexResult[0]) {
        newFooterHTML += "<img src='https://profile-counter.glitch.me/LetMeFly-LeetCodeBlog/count.svg' style='display: none'></img>"
    }
    newFooterHTML += "</div>";
    footer.html(newFooterHTML);
})