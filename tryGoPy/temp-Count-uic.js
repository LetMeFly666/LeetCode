/*
 * @Author: LetMeFly
 * @Date: 2024-12-06 10:11:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-06 10:29:25
 */
allArticles = document.querySelectorAll('[data-ng-repeat="item in section.lineItems"]')
// 所有一共356篇，UIC一共223篇


// 在allArticles中，使用js提取：从“data-ng-href”为“dfs/SWC2024-7lqVCjwlLs2N5BVwNXJmmv/208600a147/208600a147.pdf”这个元素 到 “data-ng-href”为“pdfs/SWC2024-7lqVCjwlLs2N5BVwNXJmmv/208600b800/208600b800.pdf”这个元素 的所有元素。
function getElementsBetweenInList(list, startHref, endHref) {  // 算了，还是我自己写吧
    const ans = [];
    var choose = false;
    list.forEach(element => {
        if (element.querySelector('a').getAttribute('data-ng-href') == startHref) {
            choose = true;
        }
        if (choose) {
            ans.push(element)
        }
        if (element.querySelector('a').getAttribute('data-ng-href') == endHref) {
            choose = false;
        }
    });
    return ans;
}
allArticles = document.querySelectorAll('[data-ng-repeat="item in section.lineItems"]');
startHref = 'pdfs/SWC2024-7lqVCjwlLs2N5BVwNXJmmv/208600a147/208600a147.pdf';
endHref = 'pdfs/SWC2024-7lqVCjwlLs2N5BVwNXJmmv/208600b800/208600b800.pdf';
elementsBetween = getElementsBetweenInList(allArticles, startHref, endHref);
