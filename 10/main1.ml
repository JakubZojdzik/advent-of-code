let x = ref 1;;
let res = ref 0;;
let itr = ref 0;;

let () =
    let ic = open_in "inp" in
    try
        while true do
            let line = input_line ic in
            if String.sub line 0 4 = "noop" then
            (
                itr := !itr + 1;
                if (!itr + 20) mod 40 = 0 then
                (
                    res := !res + !x * !itr;
                );
            );

            if String.sub line 0 4 = "addx" then
            (
                let nw = String.sub line 5 (String.length line - 5) in
                let nwint = int_of_string nw in
                for i = 0 to 1 do
                    itr := !itr + 1;
                    if (!itr + 20) mod 40 = 0 then
                    (
                        res := !res + !x * !itr;
                    );
                done;
                x := !x + nwint;
            );
        done
    with End_of_file ->
        close_in ic;

    Printf.printf "RESULT: %d\n" !res