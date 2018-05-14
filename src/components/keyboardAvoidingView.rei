let make:
  (
    ~accessibilityLabel: string=?,
    ~behavior: [ | `padding | `height | `position]=?,
    ~testID: string=?,
    ~keyboardVerticalOffset: float=?,
    ~contentContainerStyle: StyleRe.t=?,
    ~style: StyleRe.t=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps, unit);