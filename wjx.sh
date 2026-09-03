###
 # @Author: LetMeFly
 # @Date: 2026-09-02 12:28:27
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2026-09-02 15:37:29
### 
# curl -X POST "https://www.wjx.cn/openapi/default.aspx?action=1000101" \
#   -H "Authorization: Bearer ${WJX_API_KEY}" \
#   -H "Content-Type: application/json; charset=UTF-8" \
#   -d '{
#   "atype": 1,
#   "title": "即时通讯系统使用偏好调研",
#   "desc": "在开发即时通讯系统过程中向大家征求意见",
#   "questions": "[{\"q_index\":1,\"q_type\":3,\"q_subtype\":3,\"q_title\":\"您的性别？\",\"is_requir\":true,\"items\":[{\"item_index\":1,\"item_title\":\"男\"},{\"item_index\":2,\"item_title\":\"女\"}]}]"
#  }'




# payload=$(cat <<'EOF'
# {
#   "atype": 1,
#   "title": "即时通讯系统使用偏好调研",
#   "desc": "在开发即时通讯系统过程中向大家征求意见",
#   "questions": "[{\"q_index\":1,\"q_type\":3,\"q_subtype\":3,\"q_title\":\"您的性别？\",\"is_requir\":true,\"items\":[{\"item_index\":1,\"item_title\":\"男\"},{\"item_index\":2,\"item_title\":\"女\"}]}]"
# }
# EOF
# )

# curl -X POST "https://www.wjx.cn/openapi/default.aspx?action=1000101" \
#   -H "Authorization: Bearer ${WJX_API_KEY}" \
#   -H "Content-Type: application/json; charset=utf-8" \
#   --data-binary "$payload"



curl -X POST "https://www.wjx.cn/openapi/default.aspx?action=1000101" \
  -H "Authorization: Bearer ${WJX_API_KEY}" \
  -H "Content-Type: application/json" \
  -d '{
  "atype": 1,
  "title": "\u5373\u65f6\u901a\u8baf\u7cfb\u7edf\u4f7f\u7528\u504f\u597d\u8c03\u7814",
  "desc": "\u5728\u5f00\u53d1\u5373\u65f6\u901a\u8baf\u7cfb\u7edf\u8fc7\u7a0b\u4e2d\u5411\u5927\u5bb6\u5f81\u6c42\u610f\u89c1",
  "questions": "[{\"q_index\":1,\"q_type\":3,\"q_subtype\":3,\"q_title\":\"\\u60a8\\u7684\\u6027\\u522b\\uff1f\",\"is_requir\":true,\"items\":[{\"item_index\":1,\"item_title\":\"\\u7537\"},{\"item_index\":2,\"item_title\":\"\\u5973\"}]}]"
}'