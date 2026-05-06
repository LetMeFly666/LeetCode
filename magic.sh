THAT IS ON UBUNTU SERVER
###
 # @Author: LetMeFly
 # @Date: 2026-05-05 12:38:49
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2026-05-06 19:52:57
### 


➜  ~ docker pull nextcloud@sha256:36226b305613cdde76ee8da89a66e8a8b4fb4ef4b673bdb7b9a9d25efa14e047
docker.io/library/nextcloud@sha256:36226b305613cdde76ee8da89a66e8a8b4fb4ef4b673bdb7b9a9d25efa14e047: Pulling from library/nextcloud
3531af2bc2a9: Pull complete
df3e427b1d42: Pull complete 
e32fe875c9f9: Downloading [===============================================>   ]  113.1MB/117.8MB
6f934793218e: Download complete
342f4bf50b50: Downloading [============================>                      ]  7.771MB/13.83MB
922b3fbcca5d: Waiting
7d2dd358023f: Waiting
c17da2e8e93d: Waiting
5e0e7ed16b28: Waiting
f7122489bbe4: Waiting
4f4fb700ef54: Waiting
1a55794049ac: Waiting
3ec202fec78e: Waiting
694005539766: Waiting
bef8a0683fef: Waiting
014131e0c9b5: Waiting
4b7e97696c8a: Waiting
67626860005c: Waiting





33.0.3.2
nextcloud:2025.12.31-stable-fpm



docker tag ab3c0c2cb0c8 nextcloud:33.0.3.2-stable-fpm
docker tag de0cbb1db14d nextcloud:32.0.9-fpm
docker save nextcloud:32.0.9-fpm | xz -z > nextcloud_32.0.9.2-fpm.tar.xz


docker save nextcloud:33.0.3.2-stable-fpm | xz -z > nextcloud_33.0.3.2-stable-fpm.tar.xz


scp Let:/srv/nextcloud/nextcloud_31.0.12.3-stable-fpm.tar.xz .
scp Let:/srv/nextcloud/nextcloud_33.0.3.2-stable-fpm.tar.xz .
scp Let:/srv/nextcloud/nextcloud_32.0.9.2-fpm.tar.xz .




