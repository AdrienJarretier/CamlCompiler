(* Ecrire une fonction pair qui a un entier n associe un booléen valant vrai ssi n est pair. *)

let pair = fun n -> n mod 2 = 0;;

pair(3);;
pair(2);;
