module View =
  View.CreateComponent(
    {
      [@bs.module "react-native"] [@bs.scope "Animated"]
      external view : ReasonReact.reactClass = "View";
      let view = view;
    },
  );

module Image =
  Image.CreateComponent(
    {
      [@bs.module "react-native"] [@bs.scope "Animated"]
      external view : ReasonReact.reactClass = "Image";
      let view = view;
    },
  );

module Text =
  Text.CreateComponent(
    {
      [@bs.module "react-native"] [@bs.scope "Animated"]
      external view : ReasonReact.reactClass = "Text";
      let view = view;
    },
  );

module ScrollView = {
  type callback = RNEvent.NativeScrollEvent.t => unit;
  external wrapUpdaterShamelessly : AnimatedRe.animatedEvent => callback =
    "%identity";
  let onScrollUpdater = (~x=?, ~y=?, ~native=false, ()) =>
    wrapUpdaterShamelessly(
      AnimatedRe.event(
        [|
          {
            "nativeEvent": {
              "contentOffset": {
                "x": Js.Undefined.fromOption(x),
                "y": Js.Undefined.fromOption(y),
              },
            },
          },
        |],
        {"useNativeDriver": Js.Boolean.to_js_boolean(native)},
      ),
    );
  include
    ScrollView.CreateComponent(
      {
        [@bs.module "react-native"] [@bs.scope "Animated"]
        external view : ReasonReact.reactClass = "ScrollView";
        let view = view;
      },
    );
};
