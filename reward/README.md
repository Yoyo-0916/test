# README

+ 本程式旨在實現簡易、可抽換、可擴充的 Reward 實作，目的是用來明確 Reward 的實作介面 (Interface)。
+ 所有的函式原型 (Prototype) 與介面 (Interface) 被定義在 `reward.h`。
+ 此簡易版中，全部函式用型態 `int` 實作，未來會改成 `double` 或 `template`，並加入新 Reward。
+ 程式的範例輸出放在 `output_example.txt` 檔案之中。

#### 目前實現的 Reward

+ Random Reward
+ HPWL Reward (用來測試可擴充性)

#### 未來可做的 Reward

+ Curiosity Reward

