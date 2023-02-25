"# kv-intro"

"# kv-intro"

自分用

とりあえずwindowsでkvライブラリが動く状態に、もしかしたら色々問題があるｶﾓ

kvライブラリの導入

* Windows

    * 必要なものをダウンロード

        SourceForgeからMinGWをダウンロード

        SourceForgeからboostライブラリをダウンロード

        kvライブラリをダウンロード

    * 開発環境の導入

        MinGWをインストールし、c++のコンパイルが出来る状態にする。

        `cmd`で`g++ --version`と入力してバージョン情報が出力される事を確認。

    * ライブラリをincludeパスに突っ込む

        * boostライブラリ

            Cドラ直下に`boost`フォルダを作成

            ダウンロードしたboostライブラリを解凍する。

            `cmd`で解凍後のフォルダの場所へ移動し、以下を実行。

            `bootstrap.bat gcc`

            その後、`N`の部分を適宜変更し、以下を実行する。

            `b2 install -jN --prefix=C:\boost`

            `-jN`の`N`は物理コア数を指定する。ビルドにはかなり時間がかかる為、忘れないように。

            `C:\boost\include\boost-1_68`の`boost`フォルダをコピペする

            コピペ先は此方の環境では`C:\MinGW\include`にコピペ

            `C:\boost\lib`の中にあるファイルを全てコピペする

            コピペ先は此方の環境では`C:\MinGW\lib`にコピペ

        * kvライブラリ

            ダウンロードしたkvライブラリを解凍し、中にある`kv`フォルダをコピペする

            コピペ先は此方の環境では`C:\MinGW\include`にコピペ

            コピペ後は`C:\MinGW\include\kv`のような階層になる。

        * kvライブラリの動作確認

            エラーメッセージの文字化け防止の為、以下を実行してコマンドプロンプトの文字コードを`UTF-8`に変更する

            `chcp 65001`

            kvライブラリを解凍した後の`test`フォルダへ移動してコンパイル

            `g++ test-rounding.cc -O3 -DNDEBUG`

            コンパイルが通る事と、実行して全てOKになる事を確認する。


* VMware(ubuntu)

    boostをインストール

    `sudo apt install libboost-dev`

    kvライブラリをダウンロードして解凍

    includeフォルダにkvフォルダごとコピペ

    `sudo cp -r kv /usr/include`