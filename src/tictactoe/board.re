module Board = {
  include ReactRe.Component;
  type props = {squares: list Square.squareState, handleSquareClick: int => unit};
  let name = "Board";
  let handleClick i {props} _ => {
    props.handleSquareClick i;
    None
  };
  let breakOnThree i => i mod 3 == 0 ? <br /> : <span />;
  let render {props, updater} => {
    let foo =
      props.squares |>
      List.mapi (
        fun i s =>
          <span> (breakOnThree i) <Square value=s handleClick=(updater (handleClick i)) /> </span>
      );
    <div> (ReactRe.arrayToElement (Array.of_list foo)) </div>
  };
};

include ReactRe.CreateComponent Board;

let createElement ::squares ::handleSquareClick => wrapProps {squares, handleSquareClick};
