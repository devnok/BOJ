class String
  def presence
    self unless self.empty? or self.nil?
  end
end
ignore=<<EOF
.DS_Store
.vscode/*
!.vscode/settings.json
!.vscode/tasks.json
!.vscode/launch.json
bin/*
in/*
EOF
File.open ".gitignore","w" do |f|
  f.write ignore
end
config = {
  email: `git config user.email`.presence || "ha819ha.dev@gmail.com",
  name: `git config user.name`.presence || "devnok"
}
if Dir.exist?('.git')
    `git pull origin master`
else
  `git init`
  print "BOJ repository : "
  url = gets.chomp || "https://github.com/devnok/BOJ.git"
  puts url
  `git remote add origin #{url}`
end
`git config --local user.email #{config[:email]}`
`git config --local user.name #{config[:name]}`
print "source files path : "
boj_path = File.expand_path(gets.chomp) #absolute path
Dir.each_child(boj_path) do |f|
  if File.extname(f) == ".cpp"
    problem = File.basename(f, ".rb").to_i
    if problem > 0
      folder = (problem / 100 * 100).to_s
    else
      folder = "others"
    end
    puts Dir.exist?(folder)
    Dir.mkdir(folder) unless Dir.exist?(folder)
    `cp #{boj_path}/#{f} #{folder}/#{f}` unless File.exist?("#{folder}/#{f}")
  end
end

`git add .`
`git commit -m "#{Time.now.strftime("%Y년%m월%d일")}"`
`git push -u origin master`
