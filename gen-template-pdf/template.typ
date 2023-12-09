#set page(
  numbering: "1",
  margin: (
    x: 32pt,
    y: 32pt
  )
)

#set text(
  font: "Source Han Serif CN VF"
)

#let code(src) = [
  #set text(font: "JetBrains Mono NL")
  #raw(src.replace("\t", "  "), block: true)
]

#show: rest => columns(2, rest)

#set heading(
  numbering: "1.1"
)

#outline(
  title: "CmdBlock's XCPC Code Template"
)
