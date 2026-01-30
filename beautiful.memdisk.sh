# 1) 创建并挂载 ramfs
sudo mkdir -p /mnt/ramdisk
sudo mount -t ramfs -o mode=0755 ramfs /mnt/ramdisk

# # 2) 关闭 swap（防止内存页被写到交换分区）
# sudo swapoff -a

# 3) 将目录拷贝到内存（示例：/path/to/source -> /mnt/ramdisk）
sudo rsync -aHAX --numeric-ids /path/to/source/ /mnt/ramdisk/

# 4) 在内存盘上执行大量随机读写（示例使用 fio）
sudo fio --name=mem_test --directory=/mnt/ramdisk --rw=randrw --rwmixread=50 --bs=4k \
  --size=1G --numjobs=8 --time_based --runtime=600 --ioengine=libaio --direct=0

# （完成后）5) 将内存盘内容落盘回目标目录
sudo rsync -a --delete /mnt/ramdisk/ /path/to/backup_on_disk/
sync

# # 6) 恢复 swap（如果需要）并卸载
# sudo swapon -a
sudo umount /mnt/ramdisk