## Initialize project
1. Clone repository
```bash
git clone git@github.com:abazyshyn/wb-chat-api.git
```
2. api-gateway

   - Initialize submodules
      ```bash
      git submodule update --init --recursive --jobs <enter-amount-of-jobs>
      ```
   - Prepare Boost's build system
     ```bash
     cd api-gateway/vendor/boost/
     ./bootstrap.sh
     ```
   - Build and install Boost from its source repository
     ```bash
     ./b2 install --prefix="$HOME/.local"
     ```
