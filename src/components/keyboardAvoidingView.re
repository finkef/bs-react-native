[@bs.module "react-native"]
external keyboardAvoidingView : ReasonReact.reactClass =
  "KeyboardAvoidingView";

type make =
  (
    ~accessibilityLabel: string=?,
    ~behavior: [ | `padding | `height | `position]=?,
    ~testID: string=?,
    ~keyboardVerticalOffset: float=?,
    ~contentContainerStyle: StyleRe.t=?,
    ~style: StyleRe.t=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit
  );

let make: make =
  (
    ~accessibilityLabel=?,
    ~behavior=?,
    ~testID=?,
    ~keyboardVerticalOffset=?,
    ~contentContainerStyle=?,
    ~style=?
  ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=keyboardAvoidingView,
      ~props=
        Js.Undefined.(
          {
            "accessibilityLabel": from_opt(accessibilityLabel),
            "testID": from_opt(testID),
            "keyboardVerticalOffset": from_opt(keyboardVerticalOffset),
            "contentContainerStyle": from_opt(contentContainerStyle),
            "behavior":
              from_opt(
                UtilsRN.option_map(
                  x =>
                    switch (x) {
                    | `height => "height"
                    | `padding => "padding"
                    | `position => "position"
                    },
                  behavior
                )
              ),
            "style": from_opt(style)
          }
        )
    );
