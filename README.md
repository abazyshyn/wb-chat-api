## Initialize project
1. Clone repository
```bash
git clone git@github.com:abazyshyn/wb-chat-api.git
```
2. Initialize submodules
```bash
git submodule update --init --recursive
```
3. Prepare Boost's build system
```bash
chmod +x ./api-gateway/vendor/boost/bootstrap.sh
./api-gateway/vendor/boost/bootstrap.sh
```
4. Build and install Boost from its source repository
```bash
./api-gateway/vendor/boost/b2 \
-C api-gateway/vendor/boost \
install \
--prefix="$HOME/.local"
```
