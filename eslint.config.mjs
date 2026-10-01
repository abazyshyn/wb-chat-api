import js from "@eslint/js";
import globals from "globals";
import tseslint from "typescript-eslint";
import tseslint from "@typescript-eslint/eslint-plugin";
import { defineConfig } from "eslint/config";

export default defineConfig([
  globalIgnores(["node_modules/", "dist/", "coverage/"]),
  {
    files: ["**/*.{js,ts}"],
    extends: [js.configs.recommended, tseslint.configs.recommended],
    languageOptions: { globals: { ...globals.node, ...globals.jest } },
    rules: {
      semi: ["error", "always"],
      quotes: ["error", "double"],
      "@typescript-eslint/no-unused-vars": [
        "error",
        { argsIgnorePattern: "^_" },
      ],
    },
  },
  {
    files: ["**/*.js"],
    rules: { "@typescript-eslint/no-require-imports": "off" },
  },
]);
