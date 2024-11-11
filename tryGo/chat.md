<!--
 * @Author: LetMeFly
 * @Date: 2024-11-07 12:48:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-09 09:39:32
-->
```
def limit_attack_size(gradients, scaling_factor=0.1):
    """
    限制前 20 个恶意客户端的梯度更新大小。
    
    参数:
    - gradients: 包含 50 个客户端的梯度更新列表，每个元素是一个 NumPy 数组，表示一个客户端的梯度更新。 | 或者是一个Dict[str, Tensor]数组
    - scaling_factor: 用于限制恶意客户端梯度大小的缩放因子。默认值为 0.1。
    
    返回:
    - new_gradients: 经过处理后的梯度更新列表，前 20 个恶意客户端的更新被限制大小。
    """
    

    # 确保输入是一个包含50个客户端梯度的列表
    assert len(gradients) == 50, "梯度列表的长度应该为 50"
    
    # 复制原始梯度列表以避免修改原始数据
    new_gradients = gradients.copy()
    
    # 限制前20个恶意客户端的梯度更新大小
    for i in range(20):  # 前20个是恶意客户端
        # 获取当前客户端的梯度更新
        original_grad = new_gradients[i]
        # 使用缩放因子限制梯度大小
        limited_grad = original_grad * scaling_factor
        # 更新新的梯度
        new_gradients[i] = limited_grad
    
    return new_gradients
```
这个函数能限制前20个客户端的梯度大小，但gradients只支持长为50的list
修改这个函数使其能支持`Dict[str, Tensor]`的`gradients`
其中键不用管，值为50个客户端这个键的tensor（[50, xxxx]）





很棒，同样修改这个函数：
```
def limit_attack_direction(gradients, mixing_factor=0.4):
    """
    限制前 15 个恶意客户端的梯度方向，使其随机向一个良性客户端的梯度方向偏移。
    
    参数:
    - gradients: 包含 50 个客户端的梯度更新列表，每个元素是一个 NumPy 数组，表示一个客户端的梯度更新。
    - mixing_factor: 用于混合恶意客户端梯度方向和随机选择的良性客户端梯度方向的因子。默认值为 0.9。
    
    返回:
    - new_gradients: 经过处理后的梯度更新列表，前 15 个恶意客户端的更新被调整方向。
    """
    # 确保输入是一个包含50个客户端梯度的列表
    assert len(gradients) == 50, "梯度列表的长度应该为 50"
    
    # 复制原始梯度列表以避免修改原始数据
    new_gradients = gradients.copy()
    
    # 对前 20 个恶意客户端进行处理
    for i in range(20):  # 前20个是恶意客户端
        # 随机选择一个良性客户端（20到50的索引是20到49）
        random_benign_index = np.random.randint(20, 50)
        benign_grad = new_gradients[random_benign_index]
        
        # 获取当前恶意客户端的梯度更新
        original_grad = new_gradients[i]
        
        # 对恶意客户端和选中的良性客户端的梯度进行归一化
        original_grad_normalized = original_grad / np.linalg.norm(original_grad)
        benign_grad_normalized = benign_grad / np.linalg.norm(benign_grad)
        
        # 将恶意客户端的梯度方向调整为向良性客户端方向偏移
        adjusted_grad = mixing_factor * benign_grad_normalized + (1 - mixing_factor) * original_grad_normalized
        
        # 重新调整梯度的大小为原始大小
        adjusted_grad *= np.linalg.norm(gradients[i])
        
        # 更新新的梯度
        new_gradients[i] = adjusted_grad
    
    return new_gradients
```
