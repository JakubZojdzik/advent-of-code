let x = ref 1;;
let itr = ref 0;;

let next_iteration () =
(
    let tmp = !itr mod 40 in
    if !x >= tmp-1 && !x <= tmp+1 then
    (
        Printf.printf "#";
    )
    else
    (
        Printf.printf " ";
    );
    itr := !itr + 1;
    if !itr mod 40 = 0 then Printf.printf "\n";
);;

let () =
    let ic = open_in "inp" in
    try
        while true do
            let line = input_line ic in
            if String.sub line 0 4 = "noop" then
                next_iteration ();

            if String.sub line 0 4 = "addx" then
            (
                let nw = String.sub line 5 (String.length line - 5) in
                let nwint = int_of_string nw in
                next_iteration ();
                next_iteration ();
                x := !x + nwint;
            );
            (* Printf.printf "x = %d, itr = %d\n" !x !itr; *)
        done
    with End_of_file ->
        close_in ic;
